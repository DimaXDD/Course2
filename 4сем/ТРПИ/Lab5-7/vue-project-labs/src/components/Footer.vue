<template>
  <div class="footer">
    <div class="footer_up">
      <div>
        <h1>
          Build a beautiful
          product with Align
        </h1>
        <p>
          Align contains all the pages and sections needed to create beautiful digital products with ease.
        </p>
      </div>
      <div class="elements" v-for="elem in elems" v-bind:key="elem">
        <div>
          <h5>
            {{elem.name}}
          </h5>
          <div class="item" v-for="item in elem.items" v-bind:key="item">
            <a href="{{item.src}}}">{{item.name}}</a>
          </div>
        </div>

      </div>
    </div>

    <div class="footer_down">
      <img src="../../public/assets/Header/IMAGE.svg" alt="">
      |
      <p class="padd">| © Template by</p>
      <a href="" class="padd">Flowbase</a>
      <p class="padd">- Powered by</p>
      <a href="" class="padd">Webflow</a>

      <p>Overview</p>
      <p>Pages</p>

    </div>
  </div>
</template>

<script>
export default {
  name: "TheFooter",
  data() {
    return {
      elems:[
        {name: "Overview", items:[{src:"", name:"Overvier"},{src:"", name:"Home 1"},{src:"", name:"Home 2"},{src:"", name:"Home 3"},{src:"", name:"Pricing 1"}, {src:"", name:"Pricing 2"}]},
        {name: "Pages", items:[{src:"", name:"About 1"},{src:"", name:"About 2"},{src:"", name:"About 3"},{src:"", name:"Blog 1"},{src:"", name:"Blog 2"},{src:"", name:"Blog Post"},{src:"", name:"Team Member"},{src:"", name:"404"}, {src:"", name:"Password"}]},
        {name: "Pages", items:[{src:"", name:"Concat 1"},{src:"", name:"Concat 2"},{src:"", name:"Concat 3"},{src:"", name:"Customer Stories"},{src:"", name:"Customer Story"},{src:"", name:"Login"},{src:"", name:"Register"},{src:"", name:"Style Guide"},{src:"", name:"Changelog"}, {src:"", name:"Licence"}]},
      ],
    }
  }
}
</script>

<style scoped>
.footer{
  padding: 90px 190px 54px 190px;
  background-color: #153C3C;
}

.padd{
  padding: 0px 10px 0px 10px;
}

.footer_up h1 {
  color: #FFFFFF;
  font-family: 'Roboto';
  font-style: normal;
  font-weight: 400;
  font-size: 34px;
  line-height: 48px;
  letter-spacing: 1.6px;

  width: 300px;
}

.footer_up p{
  color: #DDE4E4;
  font-family: 'Roboto';
  font-style: normal;
  font-weight: 400;
  font-size: 15px;
  line-height: 28px;
  letter-spacing: 0.32px;
  width: 357px;
}
.footer {

}

.footer_up{
  display: flex;
  flex-wrap: wrap;
}

.elements {
  padding: 0 110px 0 100px;
}

.elements h5 {
  color: #F4F5F6;

  font-family: 'Roboto';
  font-style: normal;
  font-weight: 400;
  font-size: 16px;
  line-height: 24px;
}
.elements a {
  font-family: 'Roboto';
  font-style: normal;
  font-weight: 400;
  font-size: 14px;
  line-height: 32px;

  letter-spacing: 0.32px;

  color: #6C8989;
  text-decoration: none;
}

.footer_down {
  display: flex;
  flex-wrap: wrap;
}
.footer_down h5 {
  background: #F4F5F6;
}
.footer_down p {
  font-family: 'Roboto';
  font-style: normal;
  font-weight: 400;
  font-size: 15px;
  line-height: 24px;
  /* identical to box height, or 160% */

  letter-spacing: 0.32px;

  color: #DDE4E4;

  margin: 0;
}

.footer_down p:nth-child(6){
  margin-left: auto;
}
.footer_down p:nth-child(7){
  margin-left: 50px;
}

.footer_down a {
  font-family: 'Roboto';
  font-style: normal;
  font-weight: 400;
  font-size: 13px;
  line-height: 16px;
  /* identical to box height, or 123% */

  letter-spacing: 0.28px;

  color: #ADC9A6;

}

.footer_down {
  padding: 0;
  margin: 114px 0 0 0;
}
</style>