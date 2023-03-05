function getInput(problemUrl) {
    return fetch(problemUrl)
        .then(response => response.text())
        .then(html => {
            const parser = new DOMParser()
            const doc = parser.parseFromString(html, 'text/html')

            const inputTag = doc.querySelector(".input")
                .getElementsByTagName("pre")[0];
            const normalChildren = Array.from(inputTag.childNodes)
                .filter(node => node.tagName === 'DIV')
            if (normalChildren.length === 0) {
                return inputTag.innerText
            } else {
                return normalChildren
                    .map(node => node.innerText)
                    .join('\n')
            }
        })
}

const generateProblem = (problem, input, week = '00') => (
    `
mkdir -p week-${week}/${problem}
cp template.cpp week-${week}/${problem}/main.cpp
cat << "HERE-DOC-END" > week-${week}/${problem}/input
${input}
HERE-DOC-END
`
)


const getProperName = (problem) => (
    problem.replaceAll(' ', '-').toLowerCase().replaceAll(/[^-a-z]/g, '')
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

    let table_rows = Array.from(nodes)
    table_rows.shift()

    let resolved = await Promise.all(table_rows
        .filter(row => row.tagName === 'TR')
        .map(problem => ({
            id: problem.querySelector('td a').innerText,
            url: problem.querySelector('td a').href,
            name: problem.querySelector('td div div a').innerText
        }))
        .map(async ({id, url, name}) => ({name: getProperName(id + '-' + name), input: await getInput(url)})));
    return resolved
            .reduce((ac, {name, input}) => {
                return ac + generateProblem(name, input, week)
            }, '') +
        `
./generate-cmake.sh`
}


// Create an image
const button = document.createElement("button")
button.innerText = "Generate Folders"
button.style.position = "fixed"
button.style.top = "0"
button.style.right = "0"
button.style.zIndex = "9999"
button.style.padding = "10px"
button.style.backgroundColor = "white"
button.style.border = "1px solid black"
button.style.borderRadius = "0 0 0 10px"
button.style.cursor = "pointer"

button.onclick = async () => {
    navigator.clipboard.writeText(await generate())
}

document.body.prepend(button)

