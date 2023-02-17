let days = new Array(7);
let Monday = {
    name: "Понедельник",
    number: 1,
};
let Tuesday = {
    name: "Вторник",
    number: 2,
};
let Wednesday = {
    name: "Среда",
    number: 3,
};
let Thursday = {
    name: "Четверг",
    number: 4,
};
let Friday = {
    name: "Пятница",
    number: 5,
};
let Saturday = {
    name: "Суббота",
    number: 6,
};
let Sunday = {
    name: "Воскресенье",
    number: 7,
};
days[0] = Monday;
days[1] = Tuesday;
days[2] = Wednesday;
days[3] = Thursday;
days[4] = Friday;
days[5] = Saturday;
days[6] = Sunday;
let count = 0;
let oddDays = "";
let outDay;
do {
    outDay = prompt("Введите день недели");
} while (!isFinite(Number(outDay)) || Number(outDay) < 1 || Number(outDay) > 7);
for (let day of days) {
    if (day["number"] % 2 !== 0) {
        oddDays += day["name"] + ",\n";
        count++;
    }
}
alert("Введенный день недели: " + days[outDay - 1]["name"] + "");
alert("Количество нечетных дней: " + count + "\nНечетные дни: \n" + oddDays);
