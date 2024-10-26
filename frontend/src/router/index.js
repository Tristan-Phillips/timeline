import { createRouter, createWebHistory } from 'vue-router';
import Home from '../views/Home.vue';
import Timelines from '../views/Timelines.vue';
import Create from '../views/Create.vue';
import Profile from '../views/Profile.vue';
import Settings from '../views/Settings.vue';

const routes = [
  { path: '/', name: 'Home', component: Home },
  { path: '/timelines', name: 'Timelines', component: Timelines },
  { path: '/create', name: 'Create', component: Create },
  { path: '/profile', name: 'Profile', component: Profile },
  { path: '/settings', name: 'Settings', component: Settings },
];

const router = createRouter({
  history: createWebHistory(process.env.BASE_URL),
  routes,
});

export default router;