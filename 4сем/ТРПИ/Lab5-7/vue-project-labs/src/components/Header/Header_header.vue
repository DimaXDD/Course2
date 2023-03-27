<template>
  <div class="header">

    <Header_menu/>

    <button
        @click="isVoiceModalOpen = !isVoiceModalOpen, isVoiceModalOpen = true"
        v-bind:class="{ animated: isHover, button: NoHover}"
        v-on:mouseover="isHover = true, NoHover = false"
        v-on:mouseout="isHover = false, NoHover = true"
    >
      Buy Align
    </button>

    <Transition name="SpawnModal">
      <BaseModal
          v-if="isVoiceModalOpen"
          @close="isVoiceModalOpen = false"
          :ModelWindowContent="ModalWindow"
      >

      </BaseModal>
    </Transition>
   <!--
    //TODO анимировать кнопку
    -->
  </div>

</template>

<script>

import BaseModal from "@/components/Base/BaseModal";
import Header_menu from "@/components/Header/Header_menu";
export default {
  name: "Header_header",
  components:{
    BaseModal,
    Header_menu
  },

  emits:['close'],

  data(){
    return{
      isHover: false,
      NoHover:true,
      isVoiceModalOpen:false,
      ModalWindow:'<h1>text H1</h1><p>text p</p>'
    }
  }
}
</script>

<style scoped>
  .header {
    background-color: #153C3C;
    height: 100px;
    width: 100%;
    display: flex;
    flex-direction: row;
    align-items: center;
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
    transition: all 0.5s ease;
  }

  .animated{
    background-color: #b2d9a9;
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
    /* identical to box height, or 185% */

    scale: 95%;

    text-align: center;

    color: #FFFFFF;
    transition: all 0.5s ease;
  }
</style>
