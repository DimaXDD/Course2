<%--
  Created by IntelliJ IDEA.
  User: dimat
  Date: 20.05.2023
  Time: 1:22
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix = "fn" uri = "http://java.sun.com/jsp/jstl/functions" %>
<html>
<head>
    <title>JSTL Functions</title>
    <link rel="stylesheet" href="style/functions.css">
</head>
<body>

<c:set var="string" value="Это простая Строка"/>

<c:out value="Строка: ${string}"/>
<br/><br/>

<c:if test="${fn:contains(string, 'Это')}">
  Строка содержит слово 'простая'
</c:if>
<br/>


<c:if test = "${fn:containsIgnoreCase(string, 'с')}">
  Строка содержит 'с'
</c:if>
<br/>


<c:if test = "${fn:endsWith(string, 'а')}">
  Строка заканчивается символом 'а'
</c:if>
<br/><br/>


<c:set var = "string1" value = "Returns the index withing a string of the first occurrence of a specified substring."/>
Index of 'string': ${fn:indexOf(string1, "string")}<br/>

<c:set var = "string1" value = "Tests if an input string contains the specified substring."/>
<c:set var = "string2" value = "${fn:split(string1, ' ')}" />
<c:set var = "string3" value = "${fn:join(string2, '-')}" />
${string3}<br/><br/>

Длина строки string1: ${fn:length(string1)}<br/><br/>

<c:set var = "string1" value = "Tests if an input string contains the specified substring."/>
<c:set var = "string2" value = "${fn:replace(string1, 'substring', 'pizza')}" />
${string2}<br>

</body>
</html>
