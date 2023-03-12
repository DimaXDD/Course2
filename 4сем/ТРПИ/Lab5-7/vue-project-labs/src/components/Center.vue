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
  <div id="info_box">

    <div class="items" v-for="item in items" v-bind:key="item">
      <h5>{{item.sub_title}}</h5>
      <h1>{{item.title}}</h1>
      <div class="gallery">
        <div class="images"
             v-for="image in item.images"
             v-bind:key="image">
          <img v-bind="image"/>
        </div>
      </div>
    </div>

    <div class="other">
      <h5>OTHER</h5>
      <h1>Additional Pages</h1>

      <div class="buttons_menu">
        <div class="buttons" v-for="button in buttons" v-bind:key="button">
          <a class="button_desc" href="{{button.src}}">{{button.name}}</a>
          <img src="assets/Center/Vector_strelka.svg" alt="">
        </div>
      </div>

    </div>

    <div class="footer_bunner">
      <h1>
        Align is the stress-free way to build your website.
      </h1>
      <div id="footer_bunner_dop_info">
        <h5>
          $79
        </h5>
        <p>
          Build a better website
          faster today.
        </p>
        <p id="footer_bunner__button">Purchase</p>
      </div>
    </div>

  </div>
</template>

<script>
export default {
  name: "TheCenter",
  data() {
    return {
      under_img: {
        id: "UnderImg",
        src: "assets/Center/Vector.png",
      },
      big_img:{
        src: "assets/Center/IMAGE.png"
      },
      items:[
        {id:1, sub_title:"LANDING PAGES", title: "Discover all the pages that you can use over\n and over again.", images:[{src: "assets/Center/Frame1.png"}, {src: "assets/Center/Frame1.png"}, {src: "assets/Center/Frame1.png"}]},
        {id:2, sub_title:"COMPANY", title: "Company Pages", images:[{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"}]},
        {id:3, sub_title:"BLOG", title: "CMS Pages", images:[{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"}]},
        {id:3, sub_title:"PRICING", title: "Pricing Pages", images:[{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"}]}
      ],
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

.button_desc
{
  margin: auto;
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
#info_box{

}
.items{
  font-family: 'Roboto';
  font-style: normal;
  text-align: center;
  font-weight: 400;

  padding: 160px 0 0 0;
  text-align: center;
}
.items h5{
  display: inline-block;
  text-transform: uppercase;
  color: #153C3C;

  background: #F3F7F2;
  border-radius: 4px;
  padding: 8px 16px 8px 16px;
  margin: 0 0 13px 0;

  /*Font*/
  font-weight: 400;
  font-size: 18px;
  line-height: 32px;
}
.items h1{
  text-align: center;
  margin: auto;
  width: 612px;
  letter-spacing: 2.24px;
  color: #172426;

  padding: 0 0 100px 0;

  /*Font*/
  font-weight: 400;
  font-size: 56px;
  line-height: 64px;
}
.gallery{
  display: flex;
  justify-content: space-between;
  max-width: 1080px;
  gap:40px;
  align-items: center;
  flex-wrap: wrap;
  box-sizing: content-box;
  margin: auto;
}

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

.buttons {
  display: flex;
  flex-wrap: wrap;
}

.buttons {
  display: flex;
  flex-wrap: wrap;

  width: 510px;
  height: 120px;
  background: #F2F8F8;
  border-radius: 12px;
  margin: 40px;
  text-align: left;
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
}

.buttons img{
  margin-left: auto;
  margin-right: 51px;
}

.footer_bunner{
  background: #153C3C;
  border-radius: 8px;
  width: 1080px;
  margin: auto;
  padding-bottom:16px;
  margin-bottom: 64px;
}
.footer_bunner h1 {
  font-family: 'Roboto';
  font-style: normal;
  font-weight: 400;
  font-size: 36px;
  line-height: 48px;
  /* or 133% */

  letter-spacing: 1.6px;

  color: #FFFFFF;
  width: 434px;
  padding: 64px 0 33px 64px;
}

#footer_bunner_dop_info{
  display: flex;
  flex-wrap: wrap;
  padding-left: 64px;
  margin: 0 0 64px 0;
}

#footer_bunner_dop_info h5{
  font-family: 'Roboto';
  font-style: normal;
  font-weight: 400;
  font-size: 40px;
  line-height: 48px;
  /* identical to box height, or 120% */
  margin: 0 10px 0 0;


  color: #ADC9A6;
}
#footer_bunner_dop_info p{
  font-family: 'Roboto';
  font-style: normal;
  font-weight: 400;
  font-size: 12px;
  line-height: 24px;
  /* identical to box height, or 200% */

  letter-spacing: 0.28px;

  color: #DDE4E4;
  width: 124px;
}

#footer_bunner__button{
  background: #84A17D;
  border-radius: 4px;
  padding: 12px 42px 12px 42px;
  text-align: center;

  font-family: 'Roboto';
  font-style: normal;
  font-weight: 400;
  font-size: 13px;
  line-height: 24px;
  /* identical to box height, or 185% */

  text-align: center;

  color: #FFFFFF;
}

</style>