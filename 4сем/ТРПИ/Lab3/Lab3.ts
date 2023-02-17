//1) Примитивные типы
const str : string = "Hello world";
const logicalType1 : boolean = true;
const logicalType2 : boolean = false;
let integer : number = 10;
let float : number = 4.2;
let num : number = 3E10;

// Два вида объявления массива
let array : number[] = [2, 3, 5, 8]; 
const arrayAsCollection : Array<number> = [2, 3, 5, 8];

//Tuple
let contact: [string, string, number] = ["Dima", "+375291111111", 19];

//Any
let newVar: any = "Hello";
newVar = 21;

//2)Функция
function sayMyName(name: string) : void
{
    console.log(name);
}
sayMyName("Hello Dima");

// never - нужно указывать явно
function throwError(str: string) : never
{
    throw new Error(str);
}

function throwError2(str: string) : never
{
    while(true)
    {}
}

//3) Свои типы (alias)
type login = string | boolean;
const log: login = "abcd";
let a: login = true;

type SomeType = string | undefined | null;

//4) Интерфейс - для класса, какие поля, функции и т.п.
interface Rect{
    readonly id: string; // долько для TS, для чтения
    color?: string; // необязательное
    size:
    {
        width: number;
        height: number;
    }
}

const rect: Rect = {
    id: "12a",
    size: {
        width: 20,
        height: 40
    }
}
rect.color = "#34354";

const rect3 = {} as Rect; // приведение типов
const rect4 = <Rect>{}; // тоже самое, что сверху

// Наследование интерфейса
interface newInterface extends Rect 
{
    getArea: () => number;
}

const rect5: newInterface =
{
    id: "12a",
    size: {
        width: 12,
        height: 32
    },
    getArea(): number
    {
        return this.size.width * this.size.height;
    }
}

// Наследование классов
interface IInterface {
    time: Date
    setTime(date: Date) : void
}
    
class Clock implements IInterface
   {
    time: Date = new Date()
    setTime(date: Date): void {
         this.time = date
    }
}


// Интерфейс для объекта с большим количеством динамических ключей
interface Styles {
    [key: string]: string
}

const Css: Styles = {
    border: '1px solid black',
    marginTop: '3px',
    borderRadius: '5px'
}

//5) Enum
enum color{
    black,
    white,
    green
}

const col = color.black;
const col2 = color[1];

enum city{
    minsk = "Minsk",
    grodno = "Grodno",
    brest = "Brest"
}

const newCity = city.minsk;


//6) 
interface interfaceForFunct 
{
    x: number,
    y: number
}

function newFunct(x: number, y: number) : interfaceForFunct
{
    return {x, y}
}

//7) Классы
class newClass
{
    name: string;
    constructor(na: string)
    {
        this.name = na;
    }

    info() : string| null {
        return this.name;
    }
}

//классы полей могут создаваться в конструкторе, если указать модификатор доступа
// class Car {
//   readonly model: string
//   readonly numberOfWheels: number = 4

//   constructor(theModel: string) {
//     this.model = theModel
//   }
// }


// Модификаторы доступа
class Car {
    readonly numberOfWheels: number = 4;
    protected voice: string = ''; //для класса и наследника класса, но не объекта наследника, нельзя обращатся
    private newVar: string;
    constructor(readonly model: string) {} //или public модель
  }

  class newCar extends Car{

  }



//8) Абстрактный класс - можно наследовать, но они не компилируются
abstract class Component
{
    abstract render(): void;
    abstract info(): string;
}

class newComp extends Component
{
    render(): void {
        console.log(`Some info`);
    }

    info(): string {
        return 'some stroke';
    }
}



//8) Guards - вспомогательные конструкции, которые позволют работать с типами
function someFunction(x: string | number)
{
    if(typeof x == 'number')
    {
        return x.toFixed(2);
    }
    else {
        return x.trim();
    }
}

class MyResponse
{
    header = 'responce header';
    result = 'responce result';
}

 class MyError
 {
    header = 'error header';
    message = 'error message';
 }

 function handle(res: MyResponse | MyError)
 {
    if(res instanceof MyResponse) // приналежность объекта к классы
    {
        return {
            info: res.header + res.result
        }
    }

    else
    {
        return {
            info: res.header + res.message
        }
    }
}

type AlertType = 'sucсess' | 'danger'| 'warning';

 function setAlertType(type: AlertType)
 {
    //...something...
 }

 setAlertType('sucсess');
 //setAlertType('asas'); - NEVER
 setAlertType('warning');

 // 9)Generic
 const arrayOfNumber: Array<number> = [1,1,2,3];

 function reverse<T>(array: T[]) : T[] {
    return array.reverse();
 }

 // 10) ---------------some operators---------------
 interface Person {
    name: string
    age: number
 }

 type PersonKey = keyof Person  // >> name && age
 const myName: PersonKey = 'name'; 

 type User = {
    _id: number
    name: string
    email: string
    createdAt: Date
  }
  
  type UserKeysNoMeta1 = Exclude<keyof User, '_id' | 'createdAt'>
  type UserKeysNoMeta2 = Pick<User, 'name' | 'email'>
  
  
  let u1: UserKeysNoMeta1 = 'name'
  // u1 = '_id'