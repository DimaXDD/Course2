<%--
  Created by IntelliJ IDEA.
  User: dimat
  Date: 20.05.2023
  Time: 0:20
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="sql" uri="http://java.sun.com/jsp/jstl/sql" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>JSTL Sql</title>
    <link rel="stylesheet" href="style/sql.css">
</head>
<body>
<sql:setDataSource var = "database" driver = "com.microsoft.sqlserver.jdbc.SQLServerDriver"
                   url = "jdbc:sqlserver://DIMADD;database=Lab9_Java;trustServerCertificate=true;encrypt=false;IntegratedSecurity=false"
                   user = "sa"  password = "1111"/> <!-- данные не от Lab9, а именно от mssql!!! -->

<sql:query dataSource = "${database}" sql = "select * from telegram" var = "result" />

<h4>---- Вывод таблицы telegram ----</h4>
<table>
    <tr>
        <th>Id</th>
        <th>Name</th>
        <th>Category</th>
        <th>Subs</th>
    </tr>
    <c:forEach items="${result.rows}" var="res">
        <tr>
            <td><c:out value="${res.id}"/></td>
            <td><c:out value="${res.name}"/></td>
            <td><c:out value="${res.category}"/></td>
            <td><c:out value="${res.subs}"/></td>
        </tr>
    </c:forEach>
</table>


<h4>---- Вывод инфы про user1 ----</h4>
<sql:query dataSource="${database}" var="user" >
    SELECT * FROM Users where UserName = ?
    <sql:param value="user1" />
</sql:query>

<table>
    <tr>
        <th>Id</th>
        <th>Login</th>
        <th>Role</th>
    </tr>
    <c:forEach items="${user.rows}" var="us">
        <tr>
            <td><c:out value="${us.ID}"/></td>
            <td><c:out value="${us.UserName}"/></td>
            <td><c:out value="${us.UserRole}"/></td>
        </tr>
    </c:forEach>
</table>


<h4>---- Вывод таблицы Users до изменения----</h4>
<sql:query dataSource = "${database}" var = "user">
    SELECT * from Users;
</sql:query>

<table>
    <tr>
        <th>Id</th>
        <th>Login</th>
        <th>Role</th>
    </tr>
    <c:forEach items="${user.rows}" var="us">
        <tr>
            <td><c:out value="${us.ID}"/></td>
            <td><c:out value="${us.UserName}"/></td>
            <td><c:out value="${us.UserRole}"/></td>
        </tr>
    </c:forEach>
</table>


<h4>---- Некоторые изменения ----</h4>
<sql:transaction dataSource = "${database}">
    <sql:update var = "count">
        UPDATE Users SET UserName = 'user1555' WHERE ID = 1002
    </sql:update>
</sql:transaction>

<h4>---- Вывод таблицы Users после изменения----</h4>
<sql:query dataSource = "${database}" var = "user">
    SELECT * from Users;
</sql:query>

<table>
    <tr>
        <th>Id</th>
        <th>Login</th>
        <th>Role</th>
    </tr>
    <c:forEach items="${user.rows}" var="us">
        <tr>
            <td><c:out value="${us.ID}"/></td>
            <td><c:out value="${us.UserName}"/></td>
            <td><c:out value="${us.UserRole}"/></td>
        </tr>
    </c:forEach>
</table>

<h4>---- url ----</h4>
<a href="<c:url value="index.jsp"/>">На главную</a>
</body>
</html>
