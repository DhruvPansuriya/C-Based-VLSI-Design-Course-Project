; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_48 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x75515 (bvmul arg0_8 arg1_48)))
(let ((?x72554 (bvmul (_ bv4294967295 32) ?x75515)))
(let ((?x19890 (bvmul arg0_8 arg1_6)))
(let ((?x70315 (bvadd ?x19890 ?x72554)))
(and (distinct ?x70315 (_ bv0 32)) true))))))
(check-sat)
