<template>
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
          <a href="{{item.src}}}"
             @mousemove="onMousemove"
             :style="{ color: `hsl(${x}, 80%, 50%)` }"
             class="movearea"
          >{{item.name}}</a>
        </div>
      </div>

    </div>
  </div>
</template>

<script>
export default {
  name: "Footer_Up",
  data() {
    return {
      x: 0,
      elems:[
        {name: "Overview", items:[{src:"", name:"Overvier"},{src:"", name:"Home 1"},{src:"", name:"Home 2"},{src:"", name:"Home 3"},{src:"", name:"Pricing 1"}, {src:"", name:"Pricing 2"}]},
        {name: "Pages", items:[{src:"", name:"About 1"},{src:"", name:"About 2"},{src:"", name:"About 3"},{src:"", name:"Blog 1"},{src:"", name:"Blog 2"},{src:"", name:"Blog Post"},{src:"", name:"Team Member"},{src:"", name:"404"}, {src:"", name:"Password"}]},
        {name: "Pages", items:[{src:"", name:"Concat 1"},{src:"", name:"Concat 2"},{src:"", name:"Concat 3"},{src:"", name:"Customer Stories"},{src:"", name:"Customer Story"},{src:"", name:"Login"},{src:"", name:"Register"},{src:"", name:"Style Guide"},{src:"", name:"Changelog"}, {src:"", name:"Licence"}]},
      ],
    }
  },
  methods: {
    onMousemove(e) {
      this.x = e.clientX
    }
  }
}
</script>

<style scoped>

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
.movearea {
  transition: 0.3s background-color ease;
}
</style>