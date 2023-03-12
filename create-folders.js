const getInputs = async (problemUrl) => {
    const res = await fetch(problemUrl)
    const html = await res.text()
    
    const parser = new DOMParser()
    const doc = parser.parseFromString(html, 'text/html')
    
    const inputTags = Array.from(doc.querySelectorAll('.input'))
        .map(el => el.getElementsByTagName('pre')[0])
    
    return inputTags.map(inputTag => {
        const normalChildren = Array.from(inputTag.childNodes)
            .filter(node => node.tagName === 'DIV')
        
        if (normalChildren.length === 0) {
            return inputTag.innerText
        }

        return normalChildren
            .map(node => node.innerText)
            .join('\n')
    })
}

const generateInput = (input, idx, week, problem) => (`
cat << 'HERE-DOC-END' > week-${week}/${problem}/input-${`${idx}`.padStart(2, '0')}
${input}
HERE-DOC-END
`)

const generateProblem = (problem, inputs, week = '00') => (`
mkdir -p week-${week}/${problem}
cp template.cpp week-${week}/${problem}/main.cpp`
+
inputs
    .map((input, idx) => generateInput(input, idx, week, problem))
    .join('\n')
)


const getProperName = (problem) => (
    problem
        .replaceAll(' ', '-')
        .toLowerCase()
        .replaceAll(/[^-a-z]/g, '')
)

const getWeek = () => {
    const zerothWeek = new Date(2023, 1, 15)
    const now = new Date()

    const diff = now - zerothWeek
    const weeks = Math.floor(diff / 1000 / 3600 / 24 / 7)

    return `${weeks}`.padStart(2, '0')
}

const generate = async (week = getWeek()) => {
    const nodes = document.getElementsByClassName('problems')[0]
        .getElementsByTagName('tbody')[0]
        .childNodes

    const table_rows = Array.from(nodes)
    table_rows.shift()

    const resolved = await Promise.all(table_rows
        .filter(row => row.tagName === 'TR')
        .map(problem => ({
            id: problem.querySelector('td a').innerText,
            url: problem.querySelector('td a').href,
            name: problem.querySelector('td div div a').innerText
        }))
        .map(async ({ id, url, name }) => ({
            name: getProperName(id + '-' + name),
            inputs: await getInputs(url)
        }))
    )
    
    return resolved
        .reduce((ac, { name, inputs }) => (
            ac + generateProblem(name, inputs, week)
        ), '') +
    `
./generate-cmake.sh`
}


// Create an image
const button = document.createElement('button')
button.id = 'fetchProblemsButton'

const style = document.createElement('style')
style.innerHTML = `
#fetchProblemsButton {
    position: fixed;
    top: 0;
    right: 0;
    z-index: 9999;
    padding: 10px;
    background: white;
    border: 1px solid black;
    border-radius: 0 0 0 10px;
    cursor: pointer;
}

#fetchProblemsButton.done {
    background: #ADE0BB;
}

#fetchProblemsButton.done::after {
    content: '✔️';
    padding-left: 6px;
}

#fetchProblemsButton.failed {
    background: #E0ADAD;
}

#fetchProblemsButton.failed::after {
    content: '❌';
    padding-left: 6px;
}
`

button.innerText = 'Generate Folders'

button.onclick = async () => {
    button.classList.remove('done')
    button.classList.remove('failed')
    
    try {
        if (window.safari) {
            const getBlob = async () => {
                const gen = await generate()
                return new Blob([gen])
            }

            const item = new ClipboardItem({
                'text/plain': getBlob()
            })

            await navigator.clipboard.write([item])
        } else {
            const text = await generate()
            await navigator.clipboard.writeText(text)
        }

        button.classList.add('done')
    } catch (e) {
        console.error(e)
        button.classList.add('failed')
    }
}

document.body.prepend(style)
document.body.prepend(button)
