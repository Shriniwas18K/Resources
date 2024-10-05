import {
    Typography as TG,
    TextField as TF,
    Box as B,
    Paper as P,
    Container as C,
    Grid2 as G,
    FormControl as FC,
    Link as L,
    Button,
    Fab,
} from "@mui/material";
import React, { ChangeEvent, useState } from "react";
import { AddPhotoAlternate } from "@mui/icons-material";
// import { BUCKET_ID, COLLECTION_ID, DATABASE_ID, databases, ID, storage } from "../../../utils/appwrite";
import { useOutletContext } from "react-router-dom";
import { activeUser } from '../DashboardLayout'

export default function NewPost() {
    const [address, setAddress] = useState('');
    const [rentInINR, setRentInINR] = useState(0);
    const [numberOfRooms, setNumberOfRooms] = useState(1);
    const [areaInSqft, setAreaInSqft] = useState(0);
    const [description,setDescription]=useState('');
    const activeUserOnDevice=useOutletContext();
    // error states
    const [addressError, setAddressError] = useState('');
    const [rentInINRError, setRentInINRError] = useState('');
    const [numberOfRoomsError, setNumberOfRoomsError] = useState('');
    const [areaInSqftError, setAreaInSqftError] = useState('');

    const handleUploadClick =async (event) => {
        

        // const results=    storage.createFile(
                // BUCKET_ID, // bucketId
                // ID.unique(), // fileId
                // event.target.files[0] // file
            // )
        
        // console.log(results)
        alert('images uploaded successfully')
    };
    const data ={
        name: activeUserOnDevice.name,
        userId: activeUserOnDevice.userId,
        email: activeUserOnDevice.email,
        phone: activeUserOnDevice.phone,
        address: address,
        rentInINR: rentInINR,
        numberOfRooms: numberOfRooms,
        areaInSqft: areaInSqft,
        description: description,
        sessionId: activeUserOnDevice.sessionId
    }
    const handleSubmit =()=>{
        console.log('database')
    }

    return (<G sx={{padding:{xs:1,sm:10},marginTop:{xs:5}}}>
        <P  sx={{padding:{xs:1,sm:10}}} square={false} variant="outlined">
            <TG variant="h5" padding={1} >New Property Posting</TG>
            <TF
                label="Address"
                variant="outlined"
                margin="normal"
                value={address}
                required
                sx={{margin:1 , width:{sm:'70vw'}}}
                onChange={(event) => setAddress(event.target.value)}
                error={!!addressError}
            />
            <TF
                label="Expected Rent (rs)"
                variant="outlined"
                margin="normal"
                type="number"
                value={rentInINR}
                sx={{margin:1}}
                onChange={(event) => setRentInINR(Number(event.target.value))}
                error={!!rentInINRError} required
            />
            <TF
                label="Number of Rooms"
                variant="outlined"
                margin="normal"
                type="number"
                value={numberOfRooms}
                sx={{margin:1}}
                onChange={(event) => setNumberOfRooms(Number(event.target.value))}
                error={!!numberOfRoomsError} required
            />
            <TF
                label="Area (sqft)"
                variant="outlined"
                margin="normal"
                type="number"
                sx={{margin:1}}
                value={areaInSqft}
                onChange={(event) => setAreaInSqft(Number(event.target.value))}
                error={!!areaInSqftError} required
            />
            <TF
                label="Description"
                variant="outlined"
                margin="normal"
                value={description}
                multiline
                sx={{margin:1 , width:{sm:'70vw'}}}
                onChange={(event) => setDescription(event.target.value)}
            />
            <label>
                <input
                    type="file"
                    accept="image/*"
                    style={{ display: 'none'}}
                    onChange={handleUploadClick}
                    required
                />
                <Fab
                    color="primary"
                    aria-label="upload picture"
                    component="span"
                    sx={{
                        position: 'relative',
                        top: 0,
                        left: 0,
                        width: 56,
                        height: 56,
                        margin:1
                    }}
                >
                    <AddPhotoAlternate />
                </Fab>
            </label>
            <Button
                variant="contained"
                color="primary"
                type="submit"
                onClick={handleSubmit}
                sx={{margin:1}}
            >
                Submit
            </Button>
        </P>
    </G>)
}