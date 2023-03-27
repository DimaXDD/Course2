<template>
  <div class="menu">
    <img src="../../../public/assets/Header/IMAGE.svg">
    <li class="menu-item">Overview</li>
    <li class="menu-item">Pages</li>
    <li class="menu-item">Template</li>
  </div>
</template>

<script>
export default {
  name: "Header_menu"
}
</script>

<style scoped>

.menu {
  display: flex;
  flex-direction: row;
  align-items: center;
  justify-content: center;
  flex-wrap: wrap;
  margin-left: 50px;
}

li {
  list-style-type: none;
  margin-right: 20px;
}

.menu-item {
  display: flex;
  flex: 1 1 auto;
  margin: 0 30px;
  color: #DDE4E4;
  font-style: normal;
  font-weight: 400;
  font-size: 15px;
  line-height: 24px;
  text-align: center;
  letter-spacing: 0.32px;
  flex-wrap: wrap;
}
</style>