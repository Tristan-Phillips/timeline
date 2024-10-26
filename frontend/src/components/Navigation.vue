<template>
    <div class="sidebar">
        <h1 class="sidebar__title">Timeline</h1>
        <ul class="sidebar__nav-list">
            <li class="sidebar__nav-item">
                <router-link class="sidebar__link" to="/">Home</router-link>
            </li>
            <li class="sidebar__nav-item">
                <router-link class="sidebar__link" to="/timelines">Timelines</router-link>
            </li>
            <li class="sidebar__nav-item">
                <router-link class="sidebar__link" to="/create">Create Timeline</router-link>
            </li>
            <li class="sidebar__nav-item">
                <router-link class="sidebar__link" to="/profile">Profile</router-link>
            </li>
            <li class="sidebar__nav-item">
                <router-link class="sidebar__link" to="/settings">Settings</router-link>
            </li>
        </ul>
    </div>
</template>

<script>
export default {
    name: 'NavigationBar',
    data() {
        return {

        };
    }
};
</script>

<style scoped>
    .sidebar {
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
        width: 200px;
        height: 100vh;
        background-color: #2c3e50;
        color: #ecf0f1;
        position: fixed;
        top: 0;
        left: 0;
        overflow-y: auto;
        padding-top: 20px;
        text-align: center;
    }

    .sidebar__nav-list {
        list-style-type: none;
        padding: 0;
    }

    .sidebar__nav-item {
        margin: 10px 0;
    }

    .sidebar__link {
        color: #ecf0f1;
        text-decoration: none;
        padding: 10px;
        display: block;
        transition: background-color 0.3s;
        cursor: pointer;
    }

    .sidebar__link:hover {
        background-color: #34495e;
    }
</style>