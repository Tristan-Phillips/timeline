<template>
    <div id="app">
        <NavigationPage></NavigationPage>
        <HomePage></HomePage>
    </div>
</template>

<script>
import HomePage from './components/Home.vue'
import NavigationPage from './components/Navigation.vue'

export default {
  name: 'App',
  components: {
    HomePage,
    NavigationPage
  }
}
</script>

<style>
#app {
}
</style>
