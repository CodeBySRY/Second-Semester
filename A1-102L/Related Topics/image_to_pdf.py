import os
import hashlib
from PIL import Image
import argparse
from pathlib import Path

def get_file_hash(file_path):
    """Generate MD5 hash of a file to detect duplicates."""
    hash_md5 = hashlib.md5()
    with open(file_path, "rb") as f:
        for chunk in iter(lambda: f.read(4096), b""):
            hash_md5.update(chunk)
    return hash_md5.hexdigest()

def combine_jpg_to_pdf(folder_path, output_pdf_name="combined_images.pdf", remove_duplicates=True):
    """
    Combine all JPG images from a folder into a single PDF file.
    Automatically removes duplicate images based on file content.
    
    Args:
        folder_path (str): Path to the folder containing JPG images
        output_pdf_name (str): Name of the output PDF file
        remove_duplicates (bool): Whether to remove duplicate images (default: True)
    """
    
    # Convert to Path object for easier handling
    folder = Path(folder_path)
    
    if not folder.exists():
        print(f"Error: Folder '{folder_path}' does not exist.")
        return
    
    if not folder.is_dir():
        print(f"Error: '{folder_path}' is not a directory.")
        return
    
    # Find all JPG files (case insensitive)
    jpg_files = []
    for ext in ['*.jpg', '*.jpeg', '*.JPG', '*.JPEG']:
        jpg_files.extend(folder.glob(ext))
    
    if not jpg_files:
        print(f"No JPG files found in '{folder_path}'.")
        return
    
    print(f"Found {len(jpg_files)} JPG files initially.")
    
    # Remove duplicates based on file content
    unique_files = []
    seen_hashes = set()
    duplicates_removed = 0
    
    if remove_duplicates:
        print("Checking for duplicate images...")
        for jpg_file in jpg_files:
            file_hash = get_file_hash(jpg_file)
            if file_hash not in seen_hashes:
                seen_hashes.add(file_hash)
                unique_files.append(jpg_file)
            else:
                duplicates_removed += 1
                print(f"  Duplicate found (skipping): {jpg_file.name}")
        
        if duplicates_removed > 0:
            print(f"Removed {duplicates_removed} duplicate images.")
        else:
            print("No duplicates found.")
    else:
        unique_files = jpg_files
    
    # Sort files by name for consistent ordering
    unique_files.sort()
    
    print(f"\nProcessing {len(unique_files)} unique JPG files:")
    for i, file in enumerate(unique_files, 1):
        print(f"  {i:3d}. {file.name}")
    
    # Convert images to PDF
    try:
        images = []
        
        for i, jpg_file in enumerate(unique_files, 1):
            print(f"\nProcessing {i}/{len(unique_files)}: {jpg_file.name}")
            
            try:
                img = Image.open(jpg_file)
                print(f"  Size: {img.size[0]}x{img.size[1]} pixels, Mode: {img.mode}")
                
                # Convert to RGB if necessary (PDF requires RGB)
                if img.mode != 'RGB':
                    img = img.convert('RGB')
                    print(f"  Converted to RGB mode")
                
                images.append(img)
                
            except Exception as e:
                print(f"  Error processing {jpg_file.name}: {str(e)}")
                continue
        
        if not images:
            print("No valid images to process!")
            return
        
        # Ensure output filename has .pdf extension
        if not output_pdf_name.lower().endswith('.pdf'):
            output_pdf_name += '.pdf'
        
        # Create output path
        output_path = folder / output_pdf_name
        
        print(f"\nCreating PDF with {len(images)} pages...")
        
        # Save as PDF
        images[0].save(
            output_path,
            save_all=True,
            append_images=images[1:] if len(images) > 1 else [],
            format='PDF',
            resolution=100.0  # Maintain good quality
        )
        
        print(f"\n✅ SUCCESS!")
        print(f"PDF created: {output_path}")
        print(f"Total pages: {len(images)}")
        print(f"File size: {output_path.stat().st_size / (1024*1024):.1f} MB")
        
        if duplicates_removed > 0:
            print(f"Duplicates removed: {duplicates_removed}")
        
    except Exception as e:
        print(f"❌ Error creating PDF: {str(e)}")
    
    finally:
        # Close all images to free memory
        for img in images:
            try:
                img.close()
            except:
                pass

def main():
    parser = argparse.ArgumentParser(description="Combine JPG images into a single PDF file")
    parser.add_argument("folder", help="Path to folder containing JPG images")
    parser.add_argument("-o", "--output", default="combined_images.pdf", 
                       help="Output PDF filename (default: combined_images.pdf)")
    parser.add_argument("--keep-duplicates", action="store_true",
                       help="Keep duplicate images (default: remove duplicates)")
    
    args = parser.parse_args()
    
    combine_jpg_to_pdf(args.folder, args.output, remove_duplicates=not args.keep_duplicates)

if __name__ == "__main__":
    import sys
    
    # Check if command line arguments are provided
    if len(sys.argv) > 1:
        # Command line usage: python script.py /path/to/folder -o output.pdf
        # To keep duplicates: python script.py /path/to/folder --keep-duplicates
        main()
    else:
        # Interactive mode when no arguments provided
        print("=== JPG to PDF Converter ===")
        print()
        
        folder_path = input("Enter the folder path containing JPG images: ").strip()
        if not folder_path:
            print("No folder path provided. Exiting.")
            sys.exit(1)
        
        output_name = input("Enter output PDF name (press Enter for 'combined_images.pdf'): ").strip()
        if not output_name:
            output_name = "combined_images.pdf"
        
        # Ask about duplicates
        remove_dupes = input("Remove duplicate images? (Y/n): ").strip().lower()
        remove_duplicates = remove_dupes != 'n'
        
        print("\nStarting conversion...\n")
        combine_jpg_to_pdf(folder_path, output_name, remove_duplicates)