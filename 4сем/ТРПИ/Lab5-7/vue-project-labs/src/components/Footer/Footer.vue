<template>
  <div class="footer">

  <Footer_Up/>

  <footer_down/>

  </div>
</template>

<script>

import Footer_Up from "@/components/Footer/Footer_Up";
import footer_down from "@/components/Footer/footer_down";


export default {
  name: "TheFooter",
  components: {Footer_Up, footer_down},
}
</script>

<style scoped>
.footer{
  padding: 90px 190px 54px 190px;
  background-color: #153C3C;
}

</style>