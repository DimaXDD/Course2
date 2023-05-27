
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Авторизация</title>
    <link rel="stylesheet" type="text/css" href="styles/welcome.css">
</head>
<body>
<div align="center">
    <h4>${result}</h4><br>
    <section class="container">
        <div class="form">
            <h1>Войти</h1>
            <form method="post" action="${pageContext.request.contextPath}/controller?command=login">
                <input name="login" type="text" placeholder="Username"><br>
                <input name="password" type="password" placeholder="Password"><br><br>
                <input class="button" type="submit" value="Войти"><br>
            </form>
        </div>
    </section>
    <a href="register.jsp">Зарегистрироваться</a>
</div>
</body>
</html>