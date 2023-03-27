<template>
  <div class="footer_down">
    <img src="../../../public/assets/Header/IMAGE.svg" alt="">
    |
    <p class="padd">| © Template by</p>
    <a href="" class="padd">Flowbase</a>
    <p class="padd">- Powered by</p>
    <a href="" class="padd">Webflow</a>

    <p>Overview</p>
    <p>Pages</p>

  </div>
</template>

<script>
export default {
  name: "footer_down",
}
</script>

<style scoped>
  .padd{
    padding: 0px 10px 0px 10px;
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