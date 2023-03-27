<template>
  <!-- @click.self="close" позваляет вызвать закрытие модального окна
   при нажатии на чёрную область, при этом если не указать self
   модальное окно будет закрываться при любом нажатии на странице-->

  <div class="modal-mask">
      <!--Анимируем появление чёрного фона
      https://www.youtube.com/watch?v=4LtRkV-U82Q&ab_channel=%D0%98%D0%B3%D0%BE%D1%80%D1%8C%D0%91%D0%B0%D0%B1%D0%BA%D0%BE
      -->
    <Transition name="BgMdOvT">
      <BaseModalOverlay v-if="IsOpen" @click.self="close"/>
    </Transition>

    <Transition name="ModalBoxT">
      <div class="modal-body">
        <div class="bg-white max-2-sn mx-auto my-8">

          <div class="modal-container">

            <div v-html="ModelWindowContent">

            </div>

            <button @click="close">Close</button>

          </div>

        </div>
      </div>
    </Transition>

  </div>

</template>

<script>

import BaseModalOverlay from './BaseModalOverlay'

export default {

  components:{
    BaseModalOverlay,

  },

  props:['ModelWindowContent'],

  data(){
    return{
      IsOpen:true,
    }
  },

  emits:['close'],

  /*тут создан метод для вы*/
  methods:{
    close(){
      this.$emit('close')
    }
  }
}

</script>

<style>
.modal-mask {
  position: fixed;
  z-index: 9998;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  display: table;
}

.modal-wrapper {
  display: table-cell;
  vertical-align: middle;
}

.modal-container {
  position: relative;
  width: 300px;
  margin: 0px auto;
  padding: 20px 30px;
  background-color: #fff;
  border-radius: 2px;
  box-shadow: 0 2px 8px rgba(0, 0, 0, 0.33);
  transition: all 0.3s ease;
  font-family: Helvetica, Arial, sans-serif;
}

.modal-header h3 {
  margin-top: 0;
  color: #42b983;
}

.modal-body {
  margin: 20px 0;
}

.modal-default-button {
  float: right;
}


</style>