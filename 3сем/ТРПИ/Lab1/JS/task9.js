let question = "Где мы учимся?";
let ExpectedAnswer = "ФИТ";
let flag = false;

do {
    let EnteredAnswer = prompt(question);
    
        if (EnteredAnswer === ExpectedAnswer) {
            alert("Молодец!");
            flag = true;
        } else {
            alert("Неправильно!");
        }
} while (!flag);