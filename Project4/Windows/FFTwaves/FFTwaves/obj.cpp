#include "obj.h"
#include <iostream>
using namespace std; //laziness

void loadObj(const char* filename)
{
	// File input object
	std::ifstream obj(filename);

	// Check for successful open
	if (!obj.is_open())
		return;

	// Variables used while reading the file
	std::vector<glm::vec3> positions;     // Positions from the file
	std::vector<glm::vec3> normals;       // Normals from the file
	std::vector<glm::vec2> uvs;           // UVs from the file
	std::vector<Vertex> verts;           // Verts we're assembling
	std::vector<UINT> indices;           // Indices of these verts
	unsigned int vertCounter = 0;        // Count of vertices/indices
	char chars[100];                     // String for line reading

										 // Still good?
	while (obj.good())
	{
		// Get the line (100 characters should be more than enough)
		obj.getline(chars, 100);

		// Check the type of line
		if (chars[0] == 'v' && chars[1] == 'n')
		{
			// Read the 3 numbers directly into an XMFLOAT3
			glm::vec3 norm;
			sscanf_s(
				chars,
				"vn %f %f %f",
				&norm.x, &norm.y, &norm.z);

			// Add to the list of normals
			normals.push_back(norm);
		}
		else if (chars[0] == 'v' && chars[1] == 't')
		{
			// Read the 2 numbers directly into an XMFLOAT2
			glm::vec2 uv;
			sscanf_s(
				chars,
				"vt %f %f",
				&uv.x, &uv.y);

			// Add to the list of uv's
			uvs.push_back(uv);
		}
		else if (chars[0] == 'v')
		{
			// Read the 3 numbers directly into an XMFLOAT3
			glm::vec3 pos;
			sscanf_s(
				chars,
				"v %f %f %f",
				&pos.x, &pos.y, &pos.z);

			// Add to the positions
			positions.push_back(pos);
		}
		else if (chars[0] == 'f')
		{
			// Read the face indices into an array
			unsigned int i[12];
			int facesRead = sscanf_s(
				chars,
				"f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",
				&i[0], &i[1], &i[2],
				&i[3], &i[4], &i[5],
				&i[6], &i[7], &i[8],
				&i[9], &i[10], &i[11]);

			// - Create the verts by looking up
			//    corresponding data from vectors
			// - OBJ File indices are 1-based, so
			//    they need to be adusted
			Vertex v1;
			v1.position = positions[i[0] - 1];
			v1.uv = uvs[i[1] - 1];
			v1.normal = normals[i[2] - 1];

			Vertex v2;
			v2.position = positions[i[3] - 1];
			v2.uv = uvs[i[4] - 1];
			v2.normal = normals[i[5] - 1];

			Vertex v3;
			v3.position = positions[i[6] - 1];
			v3.uv = uvs[i[7] - 1];
			v3.normal = normals[i[8] - 1];

			// Flip the UV's since they're probably "upside down"
			v1.uv.y = 1.0f - v1.uv.y;
			v2.uv.y = 1.0f - v2.uv.y;
			v3.uv.y = 1.0f - v3.uv.y;

			// Add the verts to the vector
			verts.push_back(v1);
			verts.push_back(v2);
			verts.push_back(v3);

			// Add three more indices
			indices.push_back(vertCounter); vertCounter += 1;
			indices.push_back(vertCounter); vertCounter += 1;
			indices.push_back(vertCounter); vertCounter += 1;

			// Was there a 4th face?
			if (facesRead == 12)
			{
				// Make the last vertex
				Vertex v4;
				v4.position = positions[i[9] - 1];
				v4.uv = uvs[i[10] - 1];
				v4.normal = normals[i[11] - 1];

				// Flip the y
				v4.uv.y = 1.0f - v4.uv.y;

				// Add a whole triangle
				verts.push_back(v1);
				verts.push_back(v3);
				verts.push_back(v4);

				// Add three more indices
				indices.push_back(vertCounter); vertCounter += 1;
				indices.push_back(vertCounter); vertCounter += 1;
				indices.push_back(vertCounter); vertCounter += 1;
			}
		}

	}
	cout << "Dock loaded " << vertCounter << endl;
	// Close the file and create the actual buffers
	obj.close();
}

void setupMesh(const char* filename)
{
}