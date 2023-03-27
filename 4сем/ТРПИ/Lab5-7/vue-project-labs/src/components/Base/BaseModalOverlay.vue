<template>
  <div class="modal-mask-background" />
</template>

<script>
export default {
  name: "BaseModalOverlay"
}
</script>

<style scoped>

.modal-mask-background{
  position: fixed;
  transition: opacity 0.3s ease;
  background-color: rgba(0, 0, 0, 0.5);
  width: 100%;
  height: 100%;
}
</style>