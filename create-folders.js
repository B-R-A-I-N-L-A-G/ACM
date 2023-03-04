const generateProblem = (problem, week = '00') => (
`
mkdir -p week-${week}/${problem}
cp template.cpp week-${week}/${problem}/main.cpp
touch week-${week}/${problem}/input
`
)


const getProperName = (problem) => (
  problem.replaceAll(' ', '-').toLowerCase().replaceAll(/[^-a-z]/g, '')
)


const generate = (week = '00') => {
  const nodes = document.getElementsByClassName('problems')[0]
    .getElementsByTagName('tbody')[0]
    .childNodes

  let table_rows = Array.from(nodes)
  table_rows.shift()

  return table_rows
    .filter(row => row.tagName === 'TR')
    .map(problem => ({
      id: problem.querySelector('td a').innerText,
      name: problem.querySelector('td div div a').innerText
    }))
    .map(({ id, name }) => getProperName(id + '-' + name))
    .reduce((ac, el) => {
      return ac + generateProblem(el, week)
    },'') +
        `
./generate-cmake.sh`
}


const getWeek = () => {
  const zerothWeek = new Date(2023, 1, 15)
  const now = new Date()

  const diff = now - zerothWeek
  const weeks = Math.floor(diff / 1000 / 3600 / 24 / 7)

  return `${weeks}`.padStart(2, '0')
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

button.onclick = () => {
  navigator.clipboard.writeText(generate(getWeek()))
}

document.body.prepend(button)

