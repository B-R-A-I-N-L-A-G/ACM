let table_rows = Array.from(document.getElementsByClassName("problems")[0].getElementsByTagName("tbody")[0].childNodes);
console.log(table_rows.filter(row => row.classList && Array.from(row.classList).filter(
    class_name => class_name.includes("problem")).length)
    .map(problem => problem.querySelector("td div div a").innerText.replaceAll(" ", "-").toLowerCase().replaceAll(/[^-a-z]/g, "")).reduce((ac, el) => {
        let w = "02";
        return `${ac}\n\nmkdir -p week-${w}/${el}\ncp template.cpp week-${w}/${el}/main.cpp\ntouch week-${w}/${el}/input`
    }, ""))