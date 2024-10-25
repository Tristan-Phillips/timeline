require('dotenv').config(); // Load from config.env
const express = require('express');
const app = express();

app.use(express.json());

const port = process.env.PORT || 3000;
const hostname = process.env.HOSTNAME || 'localhost';

app.get('/', (req, res) => {
    res.send('Hello to Timeline');
});

app.listen(port, hostname, () => {
    console.log(`Server is running at http://${hostname}:${port}`);
});