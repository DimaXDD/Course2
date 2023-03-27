<template>
  <div id="info_box">

    <Center_preview/>

    <Center_items/>

    <Center_other/>

    <Center_bunner/>

  </div>
</template>

<script>
import Center_bunner from "@/components/Center/Center_bunner";
import Center_items from "@/components/Center/Center_items";
import Center_preview from "@/components/Center/Center_preview";
import Center_other from "@/components/Center/Center_other";

export default {
  name: "TheCenter",
  components: {
    Center_bunner,
    Center_other,
    Center_preview,
    Center_items
  }
}
</script>

<style scoped>

</style>