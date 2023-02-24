var array = [
    { id: 1, name: 'Vasya', group: 10 },
    { id: 2, name: 'Ivan', group: 11 },
    { id: 3, name: 'Masha', group: 12 },
    { id: 4, name: 'Petya', group: 10 },
    { id: 5, name: 'Kira', group: 11 },
];
var car = {}; //объект создан!
car.manufacturer = "manufacturer";
car.model = 'model';
var car1 = {}; //объект создан!
car1.manufacturer = "manufacturer";
car1.model = 'model';
var car2 = {}; //объект создан!
car2.manufacturer = "manufacturer";
car2.model = 'model';
var arrayCars = [{
        cars: [car1, car2]
    }];
var group = {
    students: [
        { id: 1, name: 'Илья', group: 6, marks: [
                { subject: "ОАиП", mark: 3, done: false },
                { subject: "КПО", mark: 5, done: true },
                { subject: "АиСД", mark: 6, done: true },
            ] },
        { id: 2, name: 'Никита', group: 9, marks: [
                { subject: "ООП", mark: 6, done: true },
                { subject: "БД", mark: 7, done: true },
                { subject: "ТВиМС", mark: 4, done: true },
            ] },
        { id: 3, name: 'Дима', group: 6, marks: [
                { subject: "АиСД", mark: 9, done: true },
                { subject: "КСиС", mark: 8, done: true },
                { subject: "Физика", mark: 7, done: true },
            ] },
    ],
    studentsFilter: function (group) {
        return this.students.filter(function (student) { return student.group === group; });
    },
    marksFilter: function (mark) {
        return this.students.filter(function (student) { return student.marks.filter(function (marks) { return marks.mark === mark; }).length > 0; });
    },
    deleteStudent: function (id) {
        this.students = this.students.filter(function (student) { return student.id !== id; });
    },
    mark: 6,
    group: 3
};
console.log("1-я функция");
for (var _i = 0, _a = group.marksFilter(7); _i < _a.length; _i++) {
    var student = _a[_i];
    console.log("ID: " + student.id + " Name: " + student.name);
}
;
console.log("2-я функция");
for (var _b = 0, _c = group.studentsFilter(5); _b < _c.length; _b++) {
    var stud = _c[_b];
    console.log(stud.id);
}
console.log("3-я функция");
group.deleteStudent(3);
for (var _d = 0, _e = group.students; _d < _e.length; _d++) {
    var stud = _e[_d];
    console.log(stud.id);
}
