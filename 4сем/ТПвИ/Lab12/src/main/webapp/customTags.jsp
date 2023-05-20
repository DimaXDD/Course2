<%--
  Created by IntelliJ IDEA.
  User: dimat
  Date: 20.05.2023
  Time: 11:41
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="TagLib" uri="TagLib.tld" %>
<html>
<head>
    <title>Custom tags</title>
    <link rel="stylesheet" href="style/tags.css">
</head>
<body>
<div class="container">
    <h1>Custom tags</h1>
    <TagLib:submit/>
    <TagLib:table nameTable="telegram"/>
</div>
<h4>---- url ----</h4>
<a href="<c:url value="index.jsp"/>">На главную</a>
</body>
</html>
