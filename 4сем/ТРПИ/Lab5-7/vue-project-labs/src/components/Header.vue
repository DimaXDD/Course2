<template>
    <div class="star">
      <img src="../../public/assets/Header/Vector.svg">
      Tell your customers of something important with this banner!
    </div>
    <div class="header">
      <div class="menu">
        <img src="../../public/assets/Header/IMAGE.svg">
        <li class="menu-item">Overview</li>
        <li class="menu-item">Pages</li>
        <li class="menu-item">Template</li>
      </div>
      <button class="button">Buy Align</button>
    </div>
</template>
  
<script>
  export default {
        name: "TheHeader",
        props: {
            
        }
    }
</script>

<style scoped>
.star {
  background-color: #ADC9A6;
  border-radius: 0;
  height: 40px;
  width: 100%;
  text-align: center;
  color: #153C3C;
  font-style: normal;
  font-weight: 400;
  font-size: 15px;
  line-height: 24px;
  letter-spacing: 0.24px;
  display: flex;
  align-items: center;
  justify-content: center;

}

.header {
  background-color: #153C3C;
  height: 100px;
  width: 100%;
  display: flex;
  flex-direction: row;
  align-items: center;
}

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

.button {
  background-color: #84A17D;
  border: none;
  color: #153C3C;
  font-size: 16px;
  padding: 10px 20px;
  margin-left: auto;
  border-radius: 4px;
  display: flex;
  align-items: center;
  justify-content: center;
  margin-right: 50px;
}
</style>
  