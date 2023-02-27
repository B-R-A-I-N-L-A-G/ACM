const current_week = "00";

function generate_one(problem, week = "00") {
  return `
mkdir -p week-${week}/${problem}
cp template.cpp week-${week}/${problem}/main.cpp
touch week-${week}/${problem}/input
`;
}

function get_proper_name(problem) {
  return problem.replaceAll(" ", "-").toLowerCase().replaceAll(/[^-a-z]/g, "");
}

function generate(week = "00") {
  let table_rows = Array.from(document.getElementsByClassName("problems")[0]
                                  .getElementsByTagName("tbody")[0]
                                  .childNodes);
  return table_rows
             .filter(row => row.classList &&
                            Array.from(row.classList)
                                .filter(class_name =>
                                            class_name.includes("problem"))
                                .length)
             .map(problem => problem.querySelector("td div div a").innerText)
             .map(get_proper_name)
             .reduce(
                 (ac, el) => {
                   let w = "02";
                   return ac + generate_one(el, week);
                 },
                 "") +
         `
./generate-cmake.sh`;
}

document.addEventListener('copy', (e) => {
  e.clipboardData.setData('text/plain', generate(current_week));
  e.preventDefault();
});
