let dictionaryWord = "Акустика";
let enteredAnswer = prompt("Исправьте ошибку в слове 'Окустика'?");
let positions = [];
enteredAnswer = enteredAnswer.toLowerCase().trim();
dictionaryWord = dictionaryWord.toLowerCase().trim();
if (enteredAnswer === dictionaryWord) {
    alert("Слово исправлено!");
} else {
    for (let i = 0, j = 0; i < dictionaryWord.length; i++, j++) {
        if (enteredAnswer[i] !== dictionaryWord[j]) {
            positions.push(i + 1);
            continue;
        }
    }
    alert(`Позиции ошибок: ${positions.join(", ")}`);
}