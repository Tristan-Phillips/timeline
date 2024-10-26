<template>
    <div id="app">
        <NavigationBar />
    </div>
</template>

<script>
import NavigationBar from './components/Navigation.vue'

export default {
  name: 'App',
  components: {
    NavigationBar
  }
}
</script>

<style>
#app {
    margin: 0;
    padding: 0;
}
</style>
