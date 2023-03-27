<template>
  <div class="items" v-for="item in items" v-bind:key="item">
    <h5>{{item.sub_title}}</h5>
    <h1>{{item.title}}</h1>
    <div class="gallery">
      <div class="images"
           v-for="image in item.images"
           v-bind:key="image"
           @click="handleItemClick(image)"
           @mouseout="handleItemOut(image)"
      >
          <img v-bind="image"

          />
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: "Center_items",
  data(){
    return{
      ImageViewer: false,
      items:[
        {id:1, sub_title:"LANDING PAGES", title: "Discover all the pages that you can use over\n and over again.", images:[{src: "assets/Center/Frame1.png"}, {src: "assets/Center/Frame1.png"}, {src: "assets/Center/Frame1.png"}]},
        {id:2, sub_title:"COMPANY", title: "Company Pages", images:[{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"}]},
        {id:3, sub_title:"BLOG", title: "CMS Pages", images:[{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"}]},
        {id:4, sub_title:"PRICING", title: "Pricing Pages", images:[{src: "assets/Center/Frame1.png"},{src: "assets/Center/Frame1.png"}]}
      ],

    }
  },
  methods:{
    handleItemClick(image){
      image.class = 'ViewImg'
    },
    handleItemOut(image){
      image.class = 'NoViewImg'
    }
  }
}
</script>

<style scoped>
/*Анимация картинки*/
.ViewImg{
  scale: 120%;
  transition: all 0.5s ease;
}

.NoViewImg{
  scale: 100%;
  transition: all 0.5s ease;
}
/**/
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
.movearea {
  transition: 0.3s background-color ease;
}
</style>