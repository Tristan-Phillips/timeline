#include "postgreDB.h"

PostgreDB::PostgreDB(Database* database) : m_database(database) {
    setup();
}

void PostgreDB::updateSystem() {
    std::cout << "Updating system" << std::endl;
    std::system("sudo pacman -Syu --noconfirm");
}

void PostgreDB::installPostgreSQL() {
    std::cout << "Installing PostgreSQL" << std::endl;
    std::system("sudo pacman -S postgresql --noconfirm");
}

void PostgreDB::initializeDatabaseCluster() {
    std::cout << "Initializing the database cluster...\n";
    std::system("sudo -iu postgres initdb --locale en_US.UTF-8 -D '/var/lib/postgres/data'");
}

void PostgreDB::startAndEnableService() {
    std::cout << "Starting and enabling the PostgreSQL service\n";
    std::system("sudo systemctl start postgresql.service");
    std::system("sudo systemctl enable postgresql.service");
}

void PostgreDB::createSuperuserAndDatabase() {
    std::cout << "Creating superuser and database\n";
    std::string command = "sudo -iu postgres createuser --superuser " + m_database->getUsername();
    std::system(command.c_str());
    command = "sudo -iu postgres createdb " + m_database->getDatabaseName();
    std::system(command.c_str());
}

void PostgreDB::restartService() {
    std::cout << "Restarting the PostgreSQL service\n";
    std::system("sudo systemctl restart postgresql.service");
}

void PostgreDB::configureLocalAccess() {

}

void PostgreDB::setup() {
    if (databaseExists()) {
        std::cout << "Database already exists\n";
        return;
    }
    updateSystem();
    installPostgreSQL();
    initializeDatabaseCluster();
    startAndEnableService();
    createSuperuserAndDatabase();
    configureLocalAccess();
    restartService();
    std::cout << "PostgreSQL setup complete\n";
}

bool PostgreDB::databaseExists() {
    std::string connectionString = "dbname=" + m_database->getDatabaseName() + " user=" + m_database->getUsername() + " password=" + m_database->getPassword() + " host=" + m_database->getHost() + " port=" + m_database->getPort();
    pqxx::connection connection(connectionString);
    if (connection.is_open()) {
        return true;
    }
    return false;
}