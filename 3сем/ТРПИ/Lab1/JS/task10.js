const userLogin = "Student";
const userPass = "fitfit";

let flag = false;

do {    
    let login = prompt("Введите логин");
    let pass = prompt("Введите пароль");
    
    if (login == userLogin & pass == userPass) {
        alert("Добро пожаловать "+ login);
        flag = true;
    } else {
        alert("Неверный логин или пароль");
    }
} while (!flag);