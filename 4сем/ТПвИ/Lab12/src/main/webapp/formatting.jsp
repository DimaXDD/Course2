<%--
  Created by IntelliJ IDEA.
  User: dimat
  Date: 19.05.2023
  Time: 23:36
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>JSTL Formatting</title>
  <link rel="stylesheet" href="style/formatting.css">
</head>
<body>
<h4>---- Форматирование чисел---- </h4>
  <c:set var="currentNumber" value="123"/>
  <c:out value="Число: ${currentNumber}"/> <br/>

  Формат (по умолчанию): <fmt:formatNumber value="${currentNumber}" /><br/>

  Процентный формат: <fmt:formatNumber value="${currentNumber}" type="percent"/><br/>

  <fmt:setLocale value="be-BY"/>
  Белорусские рубли:
  <fmt:formatNumber value="${currentNumber}" type="currency"/><br/>

  <fmt:setLocale value="en_US"/>
  Американские доллары:
  <fmt:formatNumber value= "${currentNumber}" type="currency"/><br/>

<h4>---- Форматирование даты/времени ----</h4>
  <jsp:useBean id="now" class="java.util.Date" />

  <fmt:setLocale value="en-EN"/>
  Вывод даты в формате English<br/>
  Сегодня: <fmt:formatDate value="${now}" /><br/>

  <fmt:setLocale value="ru-RU"/>
  <fmt:timeZone value="GMT+3:00">
  Вывод даты в формате Russian<br/>

  Сегодня: <fmt:formatDate value="${now}" type="both" dateStyle="full" timeStyle="full"/> <br/>
  </fmt:timeZone>
  <c:set var="currentDate" value="12-05-2006" />
  <fmt:parseDate value="${currentDate}" var="parsedCurrentDate" pattern="dd-MM-yyyy" />
  Парсинг строковой даты: <c:out value="${parsedCurrentDate}" />
<br/>

Стиль времени:
<br/>
  (short): <fmt:formatDate value="${now}" type="time" timeStyle="short" /><br/>
  (medium):<fmt:formatDate value="${now}" type="time" timeStyle="medium" /><br/>
  (long): <fmt:formatDate value="${now}" type="time" timeStyle="long" /><br/><br/>

<h4>---- url ----</h4>
<a href="<c:url value="index.jsp"/>">На главную</a>
</body>
</html>
