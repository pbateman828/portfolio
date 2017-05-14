package main

func main() {

  transfer := newTransfer("https://steamcdn-a.akamaihd.net/client/installer/steam.deb",
		"steam.deb")
	progress := Progress{transfer}
	progress.start()
}
