### Run the setup

## Install Docker
First you need to install Docker:

```bash
# Install Docker
sudo apt update && sudo apt install docker.io docker-compose -y

# Start Docker
sudo systemctl start docker && sudo systemctl enable docker
```

## Clone Repository

First clone the repository and change into the monitoring directors.

```bash
git clone https://github.com/shufps/ESP-Miner-NerdQAxePlus
cd ESP-Miner-NerdQAxePlus/monitoring
```

## Prepare and run Grafana and Influx

Before the setup is run, the data directories need to be created:

```
sudo ./create_data_directories.sh
```

Afterwards start with:
```
sudo docker compose up -d
```

Then, Grafana should be available at `http://localhost:3000`.

Default Username and Password is `admin` and `foobar`

To stop the monitoring use:
```
sudo docker compose down
```

## Setup InfluxDB on AxeOS

The settings should look like this (default token is `f37fh783hf8hq`):

![image](https://github.com/user-attachments/assets/aa7f86f6-890a-4d07-9904-58af239f9e80)

`Influx URL` is the IP / hostname of the computer running the Grafana + Influx Setup.



