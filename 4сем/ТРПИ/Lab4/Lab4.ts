// Выполнить типизацию данных:
// 1
type arrayType = {
    id: number, 
    name: string, 
    group: number;
}

const array : arrayType[] = [
    {id: 1, name: 'Vasya', group: 10},
    {id: 2, name: 'Ivan', group: 11},
    {id: 3, name: 'Masha', group: 12},
    {id: 4, name: 'Petya', group: 10},
    {id: 5, name: 'Kira', group: 11},
]

// 2
interface CarsType {
    manufacturer? : string,
    model? : string
}

let car: CarsType = {}; //объект создан!
car.manufacturer = "manufacturer";
car.model = 'model';

// 3
type ArrayCarsType = {
    cars: Array<CarsType>;
}

const car1: CarsType = {}; //объект создан!
car1.manufacturer = "manufacturer";
car1.model = 'model';

const car2: CarsType = {}; //объект создан!
car2.manufacturer = "manufacturer";
car2.model = 'model';

const arrayCars: Array<ArrayCarsType> = [{
    cars: [car1, car2]
}];

// 4

type MarkFilterType = 1 |2 |3 |4 |5 |6 |7 |8 |9 |10;
type DoneType = boolean;
type GroupFilterType = 1 |2 |3 |4 |5 |6 |7 |8 |9 |10 |11 |12;

type MarkType = {
    subject: string,
    mark: MarkFilterType, // может принимать значения от 1 до 10
    done: DoneType,
}
type StudentType = {
    id: number,
    name: string,
    group: GroupFilterType, // может принимать значения от 1 до 12
    marks: Array<MarkType>,
}

type GroupType = {
    students: StudentType[],
    studentsFilter: (group: number) => Array<StudentType>, // фильтр по группе
    marksFilter: (mark: number) => Array<StudentType>, // фильтр по  оценке
    deleteStudent: (id: number) => void, // удалить студента по id из  исходного массива
    mark: MarkFilterType,
    group: GroupFilterType,
}

const group: GroupType = {
    students: [
        {id: 1, name: 'Илья', group: 6, marks: [
            {subject: "ОАиП", mark: 3, done: false},
            {subject: "КПО", mark: 5, done: true},
            {subject: "АиСД", mark: 6, done: true},
            ]},
        {id: 2, name: 'Никита', group: 9, marks: [
            {subject: "ООП", mark: 6, done: true},
            {subject: "БД", mark: 7, done: true},
            {subject: "ТВиМС", mark: 4, done: true},
            ]},
        {id: 3, name: 'Дима', group: 6, marks: [
            {subject: "АиСД", mark: 9, done: true},
            {subject: "КСиС", mark: 8, done: true},
            {subject: "Физика", mark: 7, done: true},
            ]},
    ],
    studentsFilter: function(group:number) {
        return this.students.filter(student => student.group === group);
    },
    marksFilter: function(mark:number){
        return this.students.filter(student => student.marks.filter(marks => marks.mark === mark).length > 0);
    },
    deleteStudent: function (id:number) {
        this.students = this.students.filter(student => student.id !== id);
    },
    mark: 6,
    group: 3
}
console.log("1-я функция");
for (let student of group.marksFilter(7)) {
    console.log("ID: " + student.id + " Name: " + student.name);
};
console.log("2-я функция");
for (let stud of group.studentsFilter(5)) {
    console.log(stud.id);
}
console.log("3-я функция");
group.deleteStudent(3);
for(let stud of group.students) {
    console.log(stud.id);
}