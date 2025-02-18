import requests

def download_file(url, filename):
        response = requests.get(url, stream=True)
        if response.status_code == 200:
                with open(filename, 'wb') as file:
                        for chunk in response.iter_content(1024):
                                file.write(chunk)
                print(f"Download completed: {filename}")
        else:
                print(f"Failed to download file. Status code: {response.status_code}")


url = "https://i.pinimg.com/736x/bf/95/34/bf953419d76bf747cba69b55e6e03957.jpg"
path = "multimedias/" 
filename = "pikachu.png"
download_file(url, path+filename)