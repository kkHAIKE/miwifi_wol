package main

import "net/http"

func main() {
    http.HandleFunc("/wol", func(w http.ResponseWriter, req *http.Request) {
        http.ServeFile(w, req, "index.html")
    })

    http.HandleFunc("/wol.mpk", func(w http.ResponseWriter, req *http.Request) {
        http.ServeFile(w, req, "app.1.0.0.mpk")
    })

    http.ListenAndServe(":8091", nil)
}

