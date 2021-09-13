-- MySQL dump 10.13  Distrib 8.0.26, for Linux (x86_64)
--
-- Host: localhost    Database: Programacion_3
-- ------------------------------------------------------
-- Server version	8.0.26-0ubuntu0.20.04.2

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Baraja`
--

DROP TABLE IF EXISTS `Baraja`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Baraja` (
  `Cartas` varchar(3) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Baraja`
--

LOCK TABLES `Baraja` WRITE;
/*!40000 ALTER TABLE `Baraja` DISABLE KEYS */;
INSERT INTO `Baraja` VALUES ('3T');
/*!40000 ALTER TABLE `Baraja` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Empleado`
--

DROP TABLE IF EXISTS `Empleado`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Empleado` (
  `Id` varchar(15) DEFAULT NULL,
  `Nomb` varchar(50) DEFAULT NULL,
  `Gen` varchar(1) DEFAULT NULL,
  `Edad` smallint DEFAULT NULL,
  `Puesto` varchar(40) DEFAULT NULL,
  `Salario` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Empleado`
--

LOCK TABLES `Empleado` WRITE;
/*!40000 ALTER TABLE `Empleado` DISABLE KEYS */;
INSERT INTO `Empleado` VALUES ('1003-1981-09876','Lucresia Gonzáles','F',40,'Cajera',24000);
/*!40000 ALTER TABLE `Empleado` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Jugador`
--

DROP TABLE IF EXISTS `Jugador`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Jugador` (
  `Id` varchar(15) DEFAULT NULL,
  `Nomb` varchar(50) DEFAULT NULL,
  `Gen` varchar(1) DEFAULT NULL,
  `Edad` smallint DEFAULT NULL,
  `TotFichas` float DEFAULT NULL,
  `Apuesta` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Jugador`
--

LOCK TABLES `Jugador` WRITE;
/*!40000 ALTER TABLE `Jugador` DISABLE KEYS */;
INSERT INTO `Jugador` VALUES ('0801-1991-00329','Carlos Yanez','M',30,10000,10);
/*!40000 ALTER TABLE `Jugador` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-09-06  8:04:35
