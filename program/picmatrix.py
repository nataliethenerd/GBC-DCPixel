from PIL import Image

def convert_image_to_code(image_path):
    try:
        # Open the image file
        img = Image.open(image_path)

        # Get the pixel data
        pixels = list(img.convert("RGB").getdata())

        # Generate code
        code = ""
        for y in range(8):
            code += "  "
            for x in range(8):
                pixel = pixels[y * 8 + x]
                red, green, blue = pixel
                code += f"setPixel(ledData, {x}, {y}, {red}, {green}, {blue}); "
            code += "\n"

        return code
    except Exception as e:
        return f"Error: {e}"

if __name__ == "__main__":
    image_path = "..."  # Replace with your image file path
    code_output = convert_image_to_code(image_path)

    if code_output.startswith("Error"):
        print(code_output)
    else:
        with open("output_code.txt", "w") as file:
            file.write(code_output)
        print("Code generated successfully. Check output_code.txt")