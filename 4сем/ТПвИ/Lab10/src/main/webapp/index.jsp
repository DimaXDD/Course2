<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>JSP - Hello World</title>
    <link rel="stylesheet" type="text/css" href="styles/index.css">
</head>
<body>

<form method="get" action="LoginServlet" class="log-in" autocomplete="off">
    <h4>Вход</h4>
    <p>${ErrorMessage}</p>
    <div>
        <input placeholder="Логин" name="login" id="email" autocomplete="off">
        <label for="email">Логин</label>

    </div>
    <div>
        <input placeholder="Пароль" type="password" name="password" id="password" autocomplete="off">
        <label for="password">Пароль</label>
    </div>
    <button type="submit" >Войти</button>
    <a href="register.jsp" target="_self">Зарегистрироваться</a>
</form>

</body>
</html>