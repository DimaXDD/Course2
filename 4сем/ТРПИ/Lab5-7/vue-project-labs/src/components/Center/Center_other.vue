<template>
  <div class="other">

    <h5>OTHER</h5>
    <h1>Additional Pages</h1>

    <div class="buttons_menu">
      <div class="buttons"
           v-for="button in buttons"
           v-bind:key="button"
           v-bind="button"
           v-on:mouseover="BtnMouseOver(button)"
           v-on:mouseout="BtnMouseOut(button)"
      >

        <a class="button_desc" href="{{button.src}}">{{button.name}}</a>

        <img src="assets/Center/Vector_strelka.svg" alt="">
      </div>
    </div>

  </div>
</template>

<script>
export default {
  name: "Center_other",
  data(){
    return{
      isHover: false,
      NoHover: true,
      buttons:[
        {name:"UI Cards ", src:""},
        {name:"Register ", src:""},
        {name:"404 Error ", src:""},
        {name:"Changelog ", src:""},
        {name:"Login ", src:""},
        {name:"Forgot Password ", src:""},
        {name:"Style Guide ", src:""},
        {name:"Licence ", src:""},
      ],
    }
  },
  methods:{
    BtnMouseOver(item){
      item.class="animated"
    },
    BtnMouseOut(item){
      item.class="buttons"
    }

  }
}
</script>

<style scoped>
.other{
  margin: auto;
  text-align: center;
  width: 1180px;
}
.other h5{
  display: inline-block;
  background-color: #f2f7f2;
  padding: 8px 16px 8px 16px;
  border-radius: 4px;
  /*Font*/
  font-size: 18px;
  line-height: 32px;
  color: #153C3C;

  margin: 160px 0 0 0;
}
.other h1{
  font-size: 62px;
  line-height: 80px;
  letter-spacing: 2.88px;
  color: #172426;
}

.buttons_menu{
  text-align: center;
  display: flex;
  flex-wrap: wrap;
  justify-content: center;
}
/*Кнопки*/
.buttons {
  display: flex;
  flex-wrap: wrap;

  width: 510px;
  height: 120px;
  background: #F2F8F8;
  border-radius: 12px;
  margin: 40px;
  text-align: left;
  transition: all 1s ease;
}

.buttons a{
  font-family: 'Roboto';
  font-style: normal;
  font-weight: 400;
  font-size: 21px;
  line-height: 32px;
  letter-spacing: 0.96px;

  color: #172426;

  margin-left: 40px;

  text-decoration: none;
  transition: all 1s ease;
}

.buttons img{
  margin-left: auto;
  margin-right: 51px;
  transition: all 1s ease;
}
.button_desc
{
  margin: auto;
}

.animated{
  background: #b0efa6;
  transition: all 1s ease;
}
.animated img{
  margin-left: auto;
  margin-right: 39px;
  transition: all 0.5s ease;
}
</style>