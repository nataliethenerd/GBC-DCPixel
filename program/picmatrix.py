import argparse
from PIL import Image
import os
import re

def convert_image_to_bytes(image_path):
    """Converts an image into raw bytes."""
    try:
        with Image.open(image_path) as image:
            original_size = image.size

            if (original_size != (8, 8)):
                print(f"Image at '{image_path}' is {original_size}, resizing to 8x8 with aliasing.")

                image = image.resize((8, 8))

            image = image.convert("RGB")

            byte_data = list(image.tobytes())

        return byte_data, image.size
    except Exception as e:
        raise ValueError(f"Error processing image: {e}")

def update_ino_file(ino_path, byte_data, image_path, image_size):
    """Replaces the mainImage array in the .ino file with new binary data."""
    if not os.path.exists(ino_path):
        raise FileNotFoundError(f"File not found: {ino_path}")

    num_led_columns = 8
    colors_per_led = 3

    chunk_size = num_led_columns * colors_per_led

    formatted_data = ",\n    ".join(
         ", ".join(f"0x{b:02X}" for b in byte_data[i:i+chunk_size])
         for i in range(0, len(byte_data), chunk_size)
    )

    program_data = f"""
const uint8_t mainImage[NUM_BYTES] = {{
    // Image: {image_path} {image_size}
    { formatted_data }
  }};
"""

    pattern = re.compile(r"const uint8_t mainImage\[NUM_BYTES\] = \{.*?\};", re.DOTALL)

    with open(ino_path, "r") as file:
        ino_content= file.read()

    updated_content = pattern.sub(program_data.strip(), ino_content)

    with open(ino_path, "w") as file:
        file.write(updated_content)

    print("Successfully updated the mainImage array in the .ino file.")

def main():
    parser = argparse.ArgumentParser(description="Convert image into binary RGB data.")

    parser.add_argument("image_path", help="Path to the image file.")

    args = parser.parse_args()

    byte_data, image_size = convert_image_to_bytes(args.image_path)

    update_ino_file("./dcpixel/dcpixel.ino", byte_data, args.image_path, image_size)

if __name__ == "__main__":
    main()