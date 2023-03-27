<template>
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
      <p
          @click="isVoiceModalOpen = !isVoiceModalOpen"
          v-bind:class="{ animated: isHover, footer_bunner__button: NoHover}"
          v-on:mouseover="isHover = true, NoHover = false"
          v-on:mouseout="isHover = false, NoHover = true"
      >Purchase</p>

      <Transition name="SpawnModal">
        <BaseModal
            v-if="isVoiceModalOpen"
            @close="isVoiceModalOpen = false"
            :ModelWindowContent="ModalWindow"
        >

        </BaseModal>
      </Transition>

    </div>
  </div>
</template>

<!--
//TODO анимирование кнопки
-->

<script>
import BaseModal from "@/components/Base/BaseModal";

export default {
  name: "Center_bunner",
  components:{BaseModal},
  data(){
    return{
      isHover: false,
      NoHover: true,
      isVoiceModalOpen: false,
      ModalWindow:'$79'
    }
  },
  methods:{
    handleItemClick(image){
      image.class = 'ViewImg'
    },
  }
}
</script>

<style scoped>
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

  .footer_bunner__button{
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
    transition: all 0.5s ease;
  }

  /*Анимация появления\исчезания модального окна*/
  .SpawnModal-enter-active,
  .SpawnModal-leave-active {
    transition: opacity 0.5s ease;
  }

  .SpawnModal-enter-from,
  .SpawnModal-leave-to {
    opacity: 0;
  }

  /*Анимация кнопки*/
  .animated{
    background: #546750;
    border-radius: 4px;
    padding: 12px 42px 12px 42px;
    text-align: center;

    font-family: 'Roboto';
    font-style: normal;
    font-weight: 400;
    font-size: 13px;
    line-height: 24px;
    /* identical to box height, or 185% */

    scale: 95%;

    text-align: center;

    color: #FFFFFF;
    transition: all 0.5s ease;
  }
</style>