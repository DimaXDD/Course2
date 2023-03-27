<template>

  <Header_star/>

  <Header_header/>

</template>

<script>
  import Header_star from "@/components/Header/Header_star";
  import Header_header from "@/components/Header/Header_header";

  export default {
        name: "TheHeader",
        components:{Header_star,Header_header,},
        props: {
            
        }
    }
</script>

<style scoped>

</style>
  