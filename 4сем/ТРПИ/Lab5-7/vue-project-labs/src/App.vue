<template>
  <TheHeader/>
  <TheCenter/>
  <TheFooter/>
</template>

<script>

import TheHeader from './components/Header.vue'
import TheCenter from './components/Center.vue'
import TheFooter from './components/Footer.vue'

export default {
  name: 'App',
  components: {
    TheHeader,
    TheCenter,
    TheFooter
  }
}
</script>

<style>
* {
  margin: 0;
}
a {
  text-decoration: none;
}
</style>
