; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_17 () (_ BitVec 32))
(assert
 (let ((?x75318 (bvmul arg0_2 arg1_10)))
(let ((?x72807 (bvmul (_ bv4294967295 32) ?x75318)))
(let ((?x5833 (bvmul arg0_2 arg1_17)))
(let ((?x53805 (bvadd ?x5833 ?x72807)))
(and (distinct ?x53805 (_ bv0 32)) true))))))
(check-sat)
