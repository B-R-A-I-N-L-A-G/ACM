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
    table_rows.shift()
    return table_rows
            .filter(row => row.tagName == "TR")
            .map(problem => ({
                'id': problem.querySelector("td a").innerText,
                'name': problem.querySelector("td div div a").innerText
            }))
            .map(struct => get_proper_name(struct.id + "-" + struct.name))
            .reduce(
                (ac, el) => {
                    return ac + generate_one(el, week);
                },
                "") +
        `
./generate-cmake.sh`;
}

if (false)
    document.addEventListener('copy', (e) => {
        e.clipboardData.setData('text/plain', generate(current_week));
        e.preventDefault();
    });
