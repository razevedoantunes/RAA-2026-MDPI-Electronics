// HTML page of the XIAO ESP32-C6 web server
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="pt">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
        }
        span {
        }
    </style>
    <script>
        // Function to retrieve and update data from the XIAO ESP32-C6
        function updateData(endpoint, elementId) {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById(elementId).innerHTML = this.responseText;
                     if (elementId === "reqBot" && window.AppInventor) {
                        window.AppInventor.setWebViewString(this.responseText);
                    }
                }
            };
            xhttp.open("GET", endpoint, true);
            xhttp.send();
        }
        // Update data every 1 second.
        setInterval(function() {
            updateData("/button", "reqBot");
        }, 1000);
    </script>
</head>
<body>
    <p><span id="reqBot"></span></p><br>
</body>
</html>
)=====";

