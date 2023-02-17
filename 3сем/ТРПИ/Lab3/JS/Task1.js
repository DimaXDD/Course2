const N = 30; // Кол-во символов в комментарии
let wrapperOfComments = document.querySelector(".commentList");
let textForComment = `
<div class="comment">
    <span class="comment-text">TextHere</span>
</div>            
`;

// Кнопка добавления комментария
let textInput = document.querySelector(".addCommentText");
textInput.maxLength = N;

// Кнопка "Отправить"
let button = document.querySelector(".addCommentButton");
button.addEventListener("click", addComment);

function addComment() {
    let stateOfInput = textInput.style.display;
    if (stateOfInput === "none") {
        textInput.style.display = "block";
        button.innerText = "Отправить";
        textInput.focus();
    }
    else {
        let text = textInput.value;
        if (text.length > 0) {
            button.innerText = "Добавить комментарий";
            textInput.value = "";
            textInput.style.display = "none";
            text = text.replace("кот", "*");
            text = text.replace("собак", "Собак");
            text = text.replace("пес", "многоуважаемый пес");
            text = textForComment.replace("TextHere", text);
            wrapperOfComments.innerHTML += text;
        }
    }
}