<template>
  <div id="preview">
    <h5>ALIGN UI KIT FOR WEBFLOW</h5>
    <h1>
      Teams build better
      <br>
      products with<br>
      Align UI
    </h1>
    <img v-bind="under_img"/>
    <img v-bind="big_img"/>
  </div>
</template>

<script>
export default {
  name: "Center_preview",
  data() {
    return {
      under_img: {
        id: "UnderImg",
        src: "assets/Center/Vector.png",
      },
      big_img:{
        src: "assets/Center/IMAGE.png"
      },
    }
  }
}
</script>

<style scoped>
  #preview{
    font-family: 'Roboto';
    font-style: normal;
    text-align: center;
    font-weight: 400;
  }
  #preview h5{
    display: inline-block;
    background-color: #f2f7f2;
    padding: 8px 16px 8px 16px;
    border-radius: 4px;
    /*Font*/
    font-size: 18px;
    line-height: 32px;
    color: #153C3C;
  }
  #preview h1{
    font-size: 62px;
    line-height: 80px;
    letter-spacing: 2.88px;
    color: #172426;
  }

  #UnderImg{
    display: block;
    margin: auto;
    transform: translateY(-50px);
    padding: 0 0 59px 0;
  }
</style>