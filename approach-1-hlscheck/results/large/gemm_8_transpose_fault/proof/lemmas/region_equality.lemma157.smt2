; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_50 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg1_22 () (_ BitVec 32))
(assert
 (let ((?x75241 (bvmul arg0_18 arg1_50)))
(let ((?x75903 (bvmul (_ bv4294967295 32) ?x75241)))
(let ((?x13928 (bvmul arg0_18 arg1_22)))
(let ((?x55296 (bvadd ?x13928 ?x75903)))
(and (distinct ?x55296 (_ bv0 32)) true))))))
(check-sat)
